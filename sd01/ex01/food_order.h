#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

#include <stdlib.h>

struct OrderRequest;
struct OrderConfirmation;

int		check_restaurant_status(struct OrderRequest *request);
struct	OrderConfirmation *create_standard_confirmation(void);
struct	OrderConfirmation *create_preorder_confirmation(void);
void	send_confirmation_notification(struct OrderConfirmation *confirmation);

// funzione principale
int		process_food_order(struct OrderRequest *request);

#endif
