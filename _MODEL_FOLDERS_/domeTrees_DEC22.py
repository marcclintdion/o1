import bpy



#================================================================================================================
#------PRINT_DOME_TREES_RENDER
#================================================================================================================
filename =  'domeTrees_RENDER_LIST.cpp'
#=================================
#path = r"C:\marcclintdion\Documents\CONTENT_GLSL\!!!!_ELEMENTS_OF_ZELDA\THREADING\startHere_threadStable 4" #_WIN
#file = open(path  + '\\'  + 'LOCATIONS' + '\\' + filename, "w", newline="\n")#_WIN
#------
#path     = bpy.path.abspath('//')      #_OS X
path = r"/Users/marcclintdion/Documents/CONTENT_GLSL/_1_B_NEW_FORMAT/_1_B_CopperDome_DEC22/"
print(path)

file = open(path + '/' + '_MODEL_FOLDERS_' + '/' + filename, "w", newline="\n")#_OS X
#----------------------------------------------------------------------------------------------------------------


#o18_domeTree_GROUP[133][4]

for item in bpy.data.groups:
    print("groupName: ", item.name)


    file.write("//==================================================================================\n")
    counter = 0
    for object in item.objects:
        
        file.write("if(%s_isActive == true)\n" %item.name) 
        file.write("{\n")

#        file.write("    if(%s + moveSet[0] > -15.0 && %s + moveSet[0] < 15.0 && %s + moveSet[1] > -8.0 && %s + moveSet[1] < 8.0) \n" %(object.location[0], object.location[0], object.location[1], object.location[1]))
#        file.write("    {\n")

        file.write("        //================\n")
        file.write("        domeTree_4tex_POSITION[0] = %ff;                    \n" %(  object.location[0]))
        file.write("        domeTree_4tex_POSITION[1] = %ff;                    \n" %(  object.location[1]))
        file.write("        domeTree_4tex_POSITION[2] = %ff + adjustGroupHeight;\n" %(  object.location[2]))

        file.write("        domeTree_4tex_ROTATION[0] = 0.0;                    \n" )
        file.write("        domeTree_4tex_ROTATION[1] = 0.0;                    \n" )
        file.write("        domeTree_4tex_ROTATION[2] = 1.0;                    \n" )
        file.write("        domeTree_4tex_ROTATION[3] = %ff;                    \n" %(  object.rotation_euler[2] * 200))
        

        file.write("        domeTree_4tex_SCALE[0] =    %ff  / 2.524784     ;\n"    %(object.dimensions[0]))
        file.write("        domeTree_4tex_SCALE[1] =    %ff  / 2.473288     ;\n"    %(object.dimensions[1]))
        file.write("        domeTree_4tex_SCALE[2] =    %ff  / 2.821896     ;\n"    %(object.dimensions[2]))
        
        
        file.write("        adjust_UVs[0] =  0.0; adjust_UVs[1] =  0.0;\n")
        file.write("        #include \"domeTree_4tex_RENDER.cpp\"  \n")

#        file.write("    }\n")
        file.write("}\n")

        counter += 1;




        
#-----------
file.close()

