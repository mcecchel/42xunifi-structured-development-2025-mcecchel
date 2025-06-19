#include "food_order.h"

int process_order(struct OrderRequest *request)
{
	struct OrderConfirmation	*confirmation;
	int							restaurant_open;
	
	confirmation = NULL;
	restaurant_open = 0;
	if (!request)
		return (0);
	restaurant_open = check_restaurant_status(request);
	if (restaurant_open)
		confirmation = create_standard_confirmation();
	else
		confirmation = create_preorder_confirmation();
	if (!confirmation)
		return (0);
	send_confirmation_notification(confirmation);
	if (confirmation)
		free(confirmation);
	return (1);
}