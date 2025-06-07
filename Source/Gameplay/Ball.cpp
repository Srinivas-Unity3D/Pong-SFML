#include "../../Header/Gameplay/Ball.h"
#include "../../Header/Sound/SoundManager.h"

using namespace Sounds;

namespace Gameplay 
{
	Ball::Ball() 
	{
		loadTexture();
		initializeVariables();
	}

	void Ball::render(RenderWindow* game_window)
	{
		game_window->draw(pong_ball_sprite);
	}

	void Ball::loadTexture()
	{
		if (!pong_ball_texture.loadFromFile(texture_path))
		{
			throw std::runtime_error("Failed to load ball texture!");
		}
	}

	void Ball::initializeVariables()
	{
		pong_ball_sprite.setTexture(pong_ball_texture); 
		pong_ball_sprite.setScale(scale_x, scale_y);     
		pong_ball_sprite.setPosition(position_x, position_y); 

		current_state = BallState::Idle;
	}

	void Ball::move(TimeService* time_service) 
	{
		updateDelayTime(time_service->getDeltaTime());
		pong_ball_sprite.move(velocity * time_service->getDeltaTime() * speed_multiplier);
	}

	void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
	{
		const RectangleShape& player1Paddle = player1->getPaddleSprite();
		const RectangleShape& player2Paddle = player2->getPaddleSprite();

		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		FloatRect player1_bounds = player1Paddle.getGlobalBounds();
		FloatRect player2_bounds = player2Paddle.getGlobalBounds();

		if (ball_bounds.intersects(player1_bounds) && velocity.x < 0)	
		{
			velocity.x = -velocity.x;  
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
		}
		if (ball_bounds.intersects(player2_bounds) && velocity.x > 0)
		{
			velocity.x = -velocity.x;  
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
		}
		
		
	}

	void Ball::handleBoudaryCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if ((ball_bounds.top <= top_boundary && velocity.y < 0) ||
			(ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
		{
			velocity.y = -velocity.y;  
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
		}

		
	}

	void Ball::handleOutofBoundCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if (ball_bounds.left <= left_boundary)
		{
			updateLeftCollisionState(true);
			reset();        // Player 2 scores!
		}
		else if (ball_bounds.left + ball_bounds.width >= right_boundary)
		{
			updateRightCollisionState(true);
			reset();        // Player 1 scores!
		}
	}

	void Ball::reset()
	{
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = Vector2f(ball_speed, ball_speed);
	}

	void Ball::update(Paddle* player1, Paddle* player2, TimeService* time_service)
	{
		move(time_service);
		onCollision(player1, player2);
	}

	void Ball::onCollision(Paddle* player1, Paddle* player2)
	{
		handleBoudaryCollision();
		handlePaddleCollision(player1, player2);
		handleOutofBoundCollision();
	}

	void Ball::updateDelayTime(float deltaTime)
	{
		if (current_state == BallState::Idle)
		{
			elapsed_delay_time += deltaTime;
			if (elapsed_delay_time >= delay_duration)
			{
				current_state = BallState::Moving;
			}
			else
			{
				return;
			}
		}
	}

	bool Ball::isRightCollisionOccurred() {
		return had_right_collison;
	}

	void Ball::updateRightCollisionState(bool value) {
		had_right_collison = value;
	}

	bool Ball::isLeftCollisionOccurred() {
		return had_left_collison;
	}

	void Ball::updateLeftCollisionState(bool value) {
		had_left_collison = value;
	}
}