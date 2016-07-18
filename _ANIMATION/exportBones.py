import os
import bpy

sce = bpy.context.scene
ob  = bpy.context.object


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
#print('@@@@@@@@@@@@@@@@@@@@@@@@')
#print(path + "/" + modelName)


#file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN
file = open(path + '/' + modelName + '/' + actionName + '.cpp', "w", newline="\n") #_OSX

 


for frameCount in range(sce.frame_start, sce.frame_end + 1):
    sce.frame_set(frameCount)
    file.write("//========================  \n")
    file.write(     "%s_FRAME = %i          \n" %(actionName, frameCount)    )
    file.write("//------------------------  \n")

    for pbone in ob.pose.bones:
        #print(pbone.name, round(pbone.matrix[0][0], 6)) # bone in object space
   
        file.write("%s_MATRIX[%i][0]  = %f \n" %(   pbone.name, frameCount, pbone.matrix[0][0] )    )
        file.write("%s_MATRIX[%i][1]  = %f \n" %(   pbone.name, frameCount, pbone.matrix[0][1] )    )
        file.write("%s_MATRIX[%i][2]  = %f \n" %(   pbone.name, frameCount, pbone.matrix[0][2] )    )
        file.write("%s_MATRIX[%i][3]  = %f \n" %(   pbone.name, frameCount, pbone.matrix[0][3] )    )

        file.write("%s_MATRIX[%i][4]  = %f \n" %(   pbone.name, frameCount, pbone.matrix[1][0] )    )
        file.write("%s_MATRIX[%i][5]  = %f \n" %(   pbone.name, frameCount, pbone.matrix[1][1] )    )
        file.write("%s_MATRIX[%i][6]  = %f \n" %(   pbone.name, frameCount, pbone.matrix[1][2] )    )
        file.write("%s_MATRIX[%i][7]  = %f \n" %(   pbone.name, frameCount, pbone.matrix[1][3] )    )

        file.write("%s_MATRIX[%i][8]  = %f \n" %(   pbone.name, frameCount, pbone.matrix[2][0] )    )
        file.write("%s_MATRIX[%i][9]  = %f \n" %(   pbone.name, frameCount, pbone.matrix[2][1] )    )
        file.write("%s_MATRIX[%i][10] = %f \n" %(   pbone.name, frameCount, pbone.matrix[2][2] )    )
        file.write("%s_MATRIX[%i][11] = %f \n" %(   pbone.name, frameCount, pbone.matrix[2][3] )    )

        file.write("%s_MATRIX[%i][12] = %f \n" %(   pbone.name, frameCount, pbone.matrix[3][0] )    )
        file.write("%s_MATRIX[%i][13] = %f \n" %(   pbone.name, frameCount, pbone.matrix[3][1] )    )
        file.write("%s_MATRIX[%i][14] = %f \n" %(   pbone.name, frameCount, pbone.matrix[3][2] )    )
        file.write("%s_MATRIX[%i][15] = %f \n" %(   pbone.name, frameCount, pbone.matrix[3][3] )    )

        file.write("//------------------------  \n")



file.write("}; \n\n")


# Frame = 0     Can be used for the rest pose.  Now it's values can then be subtracted from all the other values for subsequent frames.
#               This should zero-out the in-Blender rotations that the bones have because they are connected to other parts' pivots.