extends Node2D

@onready var player = $Player
@onready var joystick = $UI/Joystick

func _ready():
	var input_handler = player.get_node_or_null("InputHandler")

	if input_handler:
		input_handler.set_joystick(joystick)
		var movement = player.get_node("Movement")
		
		input_handler.set_joystick(joystick)
		movement.set_input_handler(input_handler)
