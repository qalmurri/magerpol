extends Node

@onready var player = $EntityManager/Players/Player
@onready var joystick = $"../UI/CanvasLayer/Joystick"

func _ready():
	print("JoystickToPlayer Ready...")
	var input_handler = player.get_node_or_null("InputHandler")

	if input_handler:
		input_handler.set_joystick(joystick)
		var movement = player.get_node("Movement")
		
		input_handler.set_joystick(joystick)
		movement.set_input_handler(input_handler)
		
