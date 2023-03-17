import { Module } from '@nestjs/common';
import { TypeOrmModule } from '@nestjs/typeorm';
import { UsersModule } from './users/users.module';
import { LeaderboardModule } from './leaderboard/leaderboard.module';

@Module({
	imports: [
		UsersModule,
		LeaderboardModule,
		TypeOrmModule.forRoot({
			type: 'postgres',
			host: 'localhost',
			port: 3306,
			username: 'testuser',
			password: 'testuser123',
			database: 'tutorial_db',
			entities: [],
			synchronize: true,
		}),
	],
	controllers: [],
	providers: [],
})
export class AppModule {}
