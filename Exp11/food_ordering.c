#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MenuItem {
    int id;
    char name[50];
    float price;
};

struct MenuItem menu[] = {
    {1, "Burger", 120.0},
    {2, "Pizza", 250.0},
    {3, "Pasta", 180.0},
    {4, "French Fries", 90.0},
    {5, "Cold Coffee", 110.0}
};
int menuSize = 5;

struct Order {
    int id;
    char name[50];
    int quantity;
    float price;
    struct Order *next;
};

struct Stack {
    int id;
    int quantity;
    struct Stack *next;
};

// Display Menu
void displayMenu() {
    printf("\n--------- MENU ---------\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d. %s - Rs. %.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("------------------------\n");
}

// Add order to linked list
void placeOrder(struct Order **head, struct Stack **top) {
    int id, qty;
    displayMenu();
    printf("Enter item id to order: ");
    scanf("%d", &id);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    if (id < 1 || id > menuSize) {
        printf("Invalid item ID!\n");
        return;
    }

    struct Order *newOrder = (struct Order *)malloc(sizeof(struct Order));
    newOrder->id = id;
    strcpy(newOrder->name, menu[id - 1].name);
    newOrder->quantity = qty;
    newOrder->price = menu[id - 1].price * qty;
    newOrder->next = NULL;

    if (*head == NULL)
        *head = newOrder;
    else {
        struct Order *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newOrder;
    }

    // Push to stack for undo
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->id = id;
    newNode->quantity = qty;
    newNode->next = *top;
    *top = newNode;

    // Save order to file
    FILE *fp = fopen("order_history.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s (x%d) - Rs. %.2f\n", newOrder->name, qty, newOrder->price);
        fclose(fp);
    }

    printf("%s (x%d) added to order!\n", newOrder->name, qty);
}

// Cancel last order
void cancelLastOrder(struct Order **head, struct Stack **top) {
    if (*top == NULL) {
        printf("No orders to cancel!\n");
        return;
    }

    int id = (*top)->id;
    int qty = (*top)->quantity;
    struct Stack *tempStack = *top;
    *top = (*top)->next;
    free(tempStack);

    struct Order *temp = *head, *prev = NULL;
    while (temp != NULL) {
        if (temp->id == id && temp->quantity == qty) {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;
            printf("Order for %s (x%d) cancelled!\n", temp->name, qty);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Show bill
void showBill(struct Order *head) {
    if (head == NULL) {
        printf("No items in order!\n");
        return;
    }

    float total = 0;
    printf("\n------ Your Bill ------\n");
    while (head != NULL) {
        printf("%s (x%d) - Rs. %.2f\n", head->name, head->quantity, head->price);
        total += head->price;
        head = head->next;
    }
    printf("-----------------------\nTotal Amount: Rs. %.2f\n", total);
}

// Show order history from file
void showOrderHistory() {
    FILE *fp = fopen("order_history.txt", "r");
    if (fp == NULL) {
        printf("No order history available.\n");
        return;
    }

    printf("\n------ ORDER HISTORY ------\n");
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    printf("----------------------------\n");
    fclose(fp);
}

// Clear order history file
void clearOrderHistory() {
    FILE *fp = fopen("order_history.txt", "w");
    if (fp != NULL) {
        fclose(fp);
        printf("Order history cleared successfully!\n");
    } else {
        printf("Error clearing history.\n");
    }
}

int main() {
    struct Order *orderList = NULL;
    struct Stack *undoStack = NULL;
    int choice;

    printf("\n==========================================\n");
    printf("     🍔 ONLINE FOOD ORDERING SYSTEM 🍕\n");
    printf("==========================================\n");

    do {
        printf("\n1. Display Menu\n");
        printf("2. Place Order\n");
        printf("3. Cancel Last Order\n");
        printf("4. Show Bill\n");
        printf("5. Show Order History\n");
        printf("6. Clear Order History\n");
        printf("7. Exit\n");
        printf("------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                placeOrder(&orderList, &undoStack);
                break;
            case 3:
                cancelLastOrder(&orderList, &undoStack);
                break;
            case 4:
                showBill(orderList);
                break;
            case 5:
                showOrderHistory();
                break;
            case 6:
                clearOrderHistory();
                break;
            case 7:
                printf("Thank you for using Online Food Ordering System!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}
