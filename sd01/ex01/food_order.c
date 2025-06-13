#include "food_order.h"

int process_food_order(struct OrderRequest *request)
{
	int	is_open;

	// Validazione input
	if (!request)
		return (0);
	// Check status ristorante
	is_open = check_restaurant_status(request);
	// Step 2: Crea confirmation appropriate in base allo status
	struct OrderConfirmation *confirmation = NULL;
	if (is_open)
		confirmation = create_standard_confirmation();
	else
		confirmation = create_preorder_confirmation();
	if (!confirmation)
		return (0);
	send_confirmation_notification(confirmation);
	free(confirmation);
	return (1);
}