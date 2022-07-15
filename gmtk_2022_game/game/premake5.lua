
baseName = path.getbasename(os.getcwd());

project (workspaceName)
  	kind "ConsoleApp"
	define_Cpp();
    location "../_build"
    targetdir "../_bin/%{cfg.buildcfg}"
	
    filter "configurations:Release"
		kind "WindowedApp"
		entrypoint "mainCRTStartup"

	filter "action:vs*"
        debugdir "$(SolutionDir)"
		
	filter {"action:vs*", "configurations:Release"}
			kind "WindowedApp"
			entrypoint "mainCRTStartup"
	filter {}
	
    vpaths 
    {
        ["Header Files/*"] = { "include/**.h", "include/**.hpp"},
        ["Source Files/*"] = {"src/**.c", "src/**.cpp"},
    }
    files {"src/**.c", "src/**.cpp", "include/**.h", "include/**.hpp"}

    includedirs { "include", "src"}
	link_raylib();
	
	-- To link to a lib use link_to("LIB_FOLDER_NAME")