# TODO:  PLEASE_ADD_THE_TEXTURE_COPY_AND_MOVE_OPERATION_INTO_A_(IS_DIRTY)_TEST_SO_ONLY_TEXTURES_WHICH_HAVE_CHANGED_WILL_BE_SAVED

#===========
import os
import bpy
import bmesh
#===========


obj_names=[]    # names of meshes in "C-suitable" format
vtx = []        # list of dictionaries for each mesh
faces = []      # list of lists
vl = []         # list of vertices for each mesh
nl = []         # list of normals for each mesh
uvl =   []      # list of UV coords for each mesh
obj_mtx=[]      # list of local transformations for each object
obj_cnt = 0     # object count
max_vcnt= 0     # qty of vertices for biggest mesh


###########################################################
#
#   Round values of the 3D vector
#
###########################################################

def r3d(v):
    return round(v[0],6), round(v[1],6), round(v[2],6)

###########################################################
#
#   Round values of the 2D vector
#
###########################################################

def r2d(v):
    return round(v[0],6), round(v[1],6)


###########################################################
#
#   Convert object name to be suitable for C definition
#
###########################################################

def clearName(name):
    tmp=name.upper()
    ret=""
    for i in tmp:
        if (i in " ./\-+#$%^!@"):
            ret=ret+"_"
        else:
            ret=ret+i
    return ret


print('\n')     
print('\n')     
print('============================__START__====================================')
print('\n')     
print('\n')  


#====================================================================================
#----MAIN_FUNCTIONS_THAT_RELY_ON_PATH
#====================================================================================

if bpy.context.selected_objects:
    for obj in bpy.context.selected_objects:
        bpy.context.scene.objects.active = obj
        bpy.ops.object.mode_set(mode='OBJECT')

        #============================================================
        #directoryPath    = '//Jewel/_MODEL_FOLDERS_/' #<-presumably, the double slash is doing the same as the following
        #directoryPath    = "\OSL_MOUNTAINS\_MODEL_FOLDERS_\\" #<-here the escape is cancelling the escape.
        #path = bpy.path.abspath(directoryPath)

        #path = r"C:\marcclintdion\\Documents\CONTENT_GLSL\!!!!_ELEMENTS_OF_ZELDA\monkeyHeadCave\_MODEL_FOLDERS_"
        
        path = r"/Users/marcdion1974/Documents/CONTENT_GLSL/JUN_2016_A/GardenPack_A1/_MODEL_FOLDERS_/"
        
        


        #------------------------------------
        #if os.path.exists(path + "\\" + obj.name) == False:
        #    os.mkdir(path +  "\\" + obj.name)
        #print('@@@@@@@@@@@@@@@@@@@@@@@@')
        #print(path + "\\" + obj.name)
        #-----
        if os.path.exists(path + "/" + obj.name) == False:
            os.mkdir(path +  "/" + obj.name)
        print('@@@@@@@@@@@@@@@@@@@@@@@@')
        print(path + "/" + obj.name)
        
        #============================================================
        #----THE_OPEN_GL_EXPORTER_DOES_IT'S_THING
        #============================================================
        msh = obj.to_mesh(bpy.context.scene,False,'PREVIEW', True) #-------THE_'False'_IS_THE_APPLY_MODIFIERS_FLAG
        
        
        print(obj)
        print(msh)
        print(obj.name)
        print('\n')
        #============================================================
        lvdic = {} # -------------local dictionary
        lfl = [] # ---------------local faces index list
        lvl = [] # ---------------local vertex list
        lnl = [] # ---------------local normal list
        luvl = [] # --------------local uv list
        lvcnt = 0 # --------------local vertices count
        isSmooth = False
        hasUV = True    # true by default, it will be verified below
    
        print("Building for: %s\n"%obj.name)
        #============================================================ 
        if (len(msh.tessface_uv_textures) > 0):
            if (msh.tessface_uv_textures.active is None):
                hasUV=False
        else:
            hasUV = False
        #-------------------
        if (hasUV):
            activeUV = msh.tessface_uv_textures.active.data
        #============================================================ 
        obj_names.append(clearName(obj.name))
        obj_cnt+=1 
        print('objectCount =', obj_cnt)
        print('\n')
        #============================================================ 
        for i,f in enumerate(msh.tessfaces):
            isSmooth = f.use_smooth
            tmpfaces = []
            for j,v in enumerate(f.vertices):  
                vec = msh.vertices[v].co
                vec = r3d(vec)
                
                if (isSmooth):  # use vertex normal
                    nor = msh.vertices[v].normal
                else:           # use face normal
                    nor = f.normal
            
                nor = r3d(nor)
            
                if (hasUV):
                    co = activeUV[i].uv[j]
                    co = r2d(co)
                else:
                    co = (0.0, 0.0)
            
                key = vec, nor, co
                vinx = lvdic.get(key)
            
                if (vinx is None): # vertex not found
                    lvdic[key] = lvcnt
                    lvl.append(vec)
                    lnl.append(nor)
                    luvl.append(co)
                    tmpfaces.append(lvcnt)
                    lvcnt+=1
                else:
                    inx = lvdic[key]
                    tmpfaces.append(inx)
        
            if (len(tmpfaces)==3): 
                lfl.append(tmpfaces)
            else:
                lfl.append([tmpfaces[0], tmpfaces[1], tmpfaces[2]])
                lfl.append([tmpfaces[0], tmpfaces[2], tmpfaces[3]])
        
   
        bpy.data.meshes.remove(msh)
        #===============================================================    
        #update global lists and dictionaries
        vtx.append(lvdic)
        faces.append(lfl)
        vl.append(lvl)
        nl.append(lnl)
        uvl.append(luvl)
        obj_mtx.append(obj.matrix_local)
        
        #===============================================================
        #============---WRITE_INDICES========
        #===============================================================      
        numberOfFaces = len(lfl)
        numberOfIndices = numberOfFaces * 3
        #-----------------------------------
        filename = obj.name + '_INDICES' + '.cpp'
        #=======
        #file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN
        #
        file = open(path + '/' + obj.name + '/' + filename, "w", newline="\n") #_OSX
        #--------------------
        file.write("%s_INDEX_COUNT  = %d;     \n" %(obj.name, numberOfIndices ))
        file.write("//--------------------------------------\n\n")
        file.write("GLuint ")
        file.write(obj.name)
        file.write("_INDICES[] = \n{\n")
        file.write("    //numberOfIndices = %d\n" %numberOfIndices)
        file.write("\n")
        #-------------------------------------------------------------------
        for faceCount in range(numberOfFaces):#---------print the index list
            file.write("%d" %lfl[faceCount][0])
            file.write(", ")
            file.write("%d" %lfl[faceCount][1])
            file.write(", ")
            file.write("%d" %lfl[faceCount][2])
            file.write(", ")
            file.write("\n")
        #---------------------------------------
        file.write("}; \n")
        file.close()
        #=========================================================================
        #============---WRITE_VERTICES========
        #=========================================================================
        numberOfVerts    = len(lvl)
        print(numberOfVerts)
        numberOfVertices = numberOfVerts
        #-----------------------------------
        filename = obj.name + '_VBO.cpp'
        #=======
        #file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN
        #
        file = open(path + '/' + obj.name + '/' + filename, "w", newline="\n") #_OSX
        #---------------------
        file.write("GLfloat ")
        file.write(obj.name)
        file.write("[] = \n{\n")
        file.write("    //numberOfVertices = %d\n" %numberOfVertices)
        file.write("\n")
        #-------------------------------------------------------------------
        for vertCount in range(numberOfVertices):#---------print the vertex list
            file.write("\t%f " %lvl[vertCount][0])
            file.write(", ")
            file.write("\t%f " %lvl[vertCount][1])
            file.write(", ")
            file.write("\t%f " %lvl[vertCount][2])
            file.write(", ")
            file.write("\t%f " %lnl[vertCount][0])
            file.write(", ")
            file.write("\t%f " %lnl[vertCount][1])
            file.write(", ")
            file.write("\t%f " %lnl[vertCount][2])
            file.write(", ")
            file.write("\t%f " %luvl[vertCount][0])
            file.write(", ")
            file.write("\t%f " %luvl[vertCount][1])
            file.write(", ")
            file.write("\n")

        #--------------------------------------
        file.write("}; \n")  
        file.close()
        
        







    