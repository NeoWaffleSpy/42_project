import {
	MiddlewareConsumer,
	Module,
	NestModule,
	RequestMethod,
} from '@nestjs/common';
import { ValidateCustomerMiddleware } from './controllers/middleware/validate-customer.middleware';
import { UsersController } from './controllers/users/users.controller';
import { UsersService } from './service/users/users.service';

@Module({
	controllers: [UsersController],
	providers: [
		{
			provide: UsersService,
			useClass: UsersService,
		},
	],
})
export class UsersModule implements NestModule {
	configure(user: MiddlewareConsumer) {}
}
