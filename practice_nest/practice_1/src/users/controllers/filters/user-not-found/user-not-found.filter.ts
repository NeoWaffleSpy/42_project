import { ArgumentsHost, Catch, ExceptionFilter, HttpException } from '@nestjs/common';
import { Request, Response } from 'express';

@Catch(HttpException)
export class UserNotFoundFilterFilter implements ExceptionFilter {
	catch(exception: HttpException, host: ArgumentsHost) {
		console.log(exception);

		const context = host.switchToHttp();
		const request = context.getRequest<Request>();
		const response = context.getResponse<Response>();

		response.sendStatus(exception.getStatus());
	}
}
