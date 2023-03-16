import { Injectable, NestMiddleware } from '@nestjs/common';
import { NextFunction, Request, Response } from 'express';

@Injectable()
export class ValidateCustomerMiddleware implements NestMiddleware {
	use(req: Request, res: Response, next: NextFunction) {
		const { validAccount } = req.headers;
		console.log('Hello there');
		if (validAccount) next();
		else res.status(401);
	}
}
