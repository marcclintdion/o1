import os
import bpy

sce = bpy.context.scene
ob = bpy.context.object


actionName  = "legArmFlopMarc"
modelName   = "marc"

path        = r"/Users/marcclintdion/Documents/CONTENT_GLSL/_1_B_NEW_FORMAT/_1_B_CopperDome_DEC29/_ANIMATION"

#------------------------------------
#if os.path.exists(path + "\\" + obj.name) == False:    #_WIN
#    os.mkdir(path +  "\\" + obj.name)
#print('@@@@@@@@@@@@@@@@@@@@@@@@')
#print(path + "\\" + obj.name)
#-----
if os.path.exists(path + "/" + modelName) == False:      #_OSX
    os.mkdir(path +  "/" + modelName)
print('@@@@@@@@@@@@@@@@@@@@@@@@')
print(path + "/" + modelName)


filename = actionName + '.cpp'
#file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN
file = open(path + '/' + modelName + '/' + actionName, "w", newline="\n") #_OSX

 


for f in range(sce.frame_start, sce.frame_end+1):
    sce.frame_set(f)
    print("Frame %i" % f)

    for pbone in ob.pose.bones:
        #print(pbone.name, round(pbone.matrix[0][0], 6)) # bone in object space
        file.write(    "GLFloat[] = %s_MATRIX  = %f;     \n" %(   pbone.name, round(pbone.matrix[0][0], 6)   )    )
