#include "Mode.hpp"

#include "Scene.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} left, right, down, up;

	//local copy of the game scene (so code can change it during gameplay):
	Scene scene;

	// Player cube
	Scene::Transform *boxy = nullptr;
	Scene::Transform *cheese = nullptr;

	const float FloorX = 2.0f;
	const float FloorY = 1.5f;
	
	//camera:
	Scene::Camera *camera = nullptr;

	// Game Timer
	float timer = 3.0f;

	// Score
	unsigned int score = 0;
	unsigned int best_score = 0;

	bool is_game_over = false;

	void spawn_cheese();
};
