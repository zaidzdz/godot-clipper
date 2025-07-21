# godot-clipper
> [!WARNING]
> Only macOS is supported currently

Unofficial [clipper2](https://github.com/AngusJohnson/Clipper2) port/wrapper to Godot. Even though Godot already uses Clipper2 in their geometry class, godot-clipper is a less bloated alternative.

## Getting started

Download the current release for your operating system and put the demo folder inside your project.  
After this, you're all set.

## Documentation
#### To create a clipper object first do ``` Clipper.new() ```
In godot-clipper, there are only four methods:
  > ## difference_polygons
  > Returns the difference of two polygons to an Array containing two PackedVector2Arrays, the subject at [0] and the clip at [1].
  
  > ## intersect_polygons
  >	Returns the intersection of two polygons to an Array containing two PackedVector2Arrays, the subject at [0] and the clip at [1].
  
  > ## union_polygons
  > Returns the union of two polygons to an Array containing two PackedVector2Arrays, only returns one PackedVector2Array at 0.
  
  > ## xor_polygons
  > Returns the XOR of two polygons to an Array containing two PackedVector2Arrays, the subject at [0] and the clip at [1].

## Example Code
```python
extends Polygon2D
#create the subject and the clip
@export var subject:PackedVector2Array
@export var clip:PackedVector2Array

#create the clipper object
var clipper = Clipper.new()

func _ready() -> void:
  #use the union operation and set the polygon's polygons to the output of the union operation 
	var union_operation = clipper.union_polygons(subject,clip)
	polygon = union[0]

```
