import { Injectable } from '@nestjs/common';

@Injectable()
export class CustomersService {
	findCustomer() {
		return {
			id: 1,
			email: 'ncaba@42.fr',
			createdAt: new Date(),
		};
	}
}
