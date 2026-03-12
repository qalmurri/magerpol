                    ┌───────────────┐
                    │   Joystick    │
                    │   (UI Node)   │
                    └───────┬───────┘
                            │
                            ▼
                    ┌───────────────┐
                    │ PlayerInput   │
                    │ get_direction │
                    └───────┬───────┘
                            │
                            ▼
          ┌─────────────────────────────────┐
          │ Player::_physics_process(delta) │
          └─────────────────────────────────┘
                            │
                            ▼
             ┌─────────────────────────────┐
             │ PlayerStateMachine::update  │
             └───────────┬─────────────────┘
                         │
        ┌────────────────┴─────────────────┐
        ▼                                  ▼
 direction.length() > 0 ?               direction == 0
        WALK                               IDLE
        │                                   │
        ▼                                   ▼
player->play_animation("walk")      player->play_animation("idle")
        │                                   │
        ▼                                   ▼
 ┌─────────────────────┐             ┌─────────────────────┐
 │ PlayerMovement::move│             │ PlayerMovement::move│
 │   (CharacterBody2D) │             │   (CharacterBody2D) │
 └─────────┬───────────┘             └─────────┬───────────┘
           │                                   │
           ▼                                   ▼
  CharacterBody2D position updated      CharacterBody2D position unchanged
           │                                   │
           ▼                                   ▼
     ┌───────────────┐                   ┌───────────────┐
     │ AnimationPlayer│                   │ AnimationPlayer│
     │ update frame   │                   │ update frame   │
     └───────┬───────┘                   └───────┬───────┘
             │                                   │
             ▼                                   ▼
   Visual/Sprite parts animated           Visual/Sprite parts idle
             │                                   │
             ▼                                   ▼
      ┌───────────────┐                     ┌───────────────┐
      │ PlayerCamera   │                     │ PlayerCamera   │
      │ follow Player  │                     │ follow Player  │
      └───────┬───────┘                     └───────┬───────┘
              │                                   │
              ▼                                   ▼
   ┌───────────────────────────┐       ┌───────────────────────────┐
   │ Other Systems Update       │       │ Other Systems Update       │
   │ (Inventory, Interaction)   │       │ (Inventory, Interaction)   │
   └───────────────────────────┘       └───────────────────────────┘
