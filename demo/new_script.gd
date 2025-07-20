extends Polygon2D
@export var subject:PackedVector2Array
@export var clip:PackedVector2Array
@onready  var othergon = $"../Polygon2D2"

var clipper = Clipper.new()

func _ready() -> void:
	var newgon = clipper.xor_polygons(subject,clip)
	polygon = newgon[1]
	print(newgon)
