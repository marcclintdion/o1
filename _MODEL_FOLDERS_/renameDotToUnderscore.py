import bpy

if bpy.context.selected_objects:
    for obj in bpy.context.selected_objects:
        bpy.context.scene.objects.active = obj
        bpy.ops.object.mode_set(mode='OBJECT')
        
