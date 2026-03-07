extends TouchScreenButton

@onready var Knob = $Knob
@onready var MaxDistance = shape.radius

var StickCenter: Vector2 = texture_normal.get_size()/2
var touched := false
var output : Vector2

func _ready():
	StickCenter = texture_normal.get_size() / 2
	Knob.position = StickCenter
	set_process(false)

func _input(event):
	if event is InputEventScreenTouch:
		if event.pressed:
			touched = true
			set_process(true)
		else:
			touched = false
			set_process(false)
			
			Knob.position = StickCenter	
			output = Vector2.ZERO
			
func _process(_delta):
	if not touched:
		return
		
	Knob.global_position = get_global_mouse_position()
	Knob.position = StickCenter + (Knob.position - StickCenter).limit_length(MaxDistance)
	output = (Knob.position - StickCenter).normalized()

func direction() -> Vector2:
	return output
