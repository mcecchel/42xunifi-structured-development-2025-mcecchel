#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

#include <stdlib.h>

struct OrderRequest
{
	char	*restaurant_id;
	char	*items;
	char	*delivery_address;
	char	*timestamp;
};

struct OrderConfirmation
{
	char	*order_id;
	char	*confirmation_message;
	char	*estimated_delivery;
	int		is_preorder;
};

// Helper functions
int		check_restaurant_status(struct OrderRequest *request);
struct	OrderConfirmation *create_standard_confirmation(void);
struct	OrderConfirmation *create_preorder_confirmation(void);
void	send_confirmation_notification(struct OrderConfirmation *confirmation);

// Main function
int		process_food_order(struct OrderRequest *request);

#endif