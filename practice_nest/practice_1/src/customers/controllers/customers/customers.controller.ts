import { Controller } from '@nestjs/common';

@Controller('customers')
export class CustomersController {
	@Get('')
	getCustomer() {
		return {
			id: 1,
			email: 'ncaba@42.fr',
			createdAt: new Date(),
		};
	}
}
