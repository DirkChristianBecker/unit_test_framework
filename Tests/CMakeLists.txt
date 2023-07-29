file(GLOB files "*.cpp")
foreach(file ${files})
	cmake_path(GET file STEM file_name)
	# Message("Test case '${file_name}'")
	set(BINARY ${file_name})

	add_executable(${BINARY} ${file} ${PROJECT_SOURCE_DIR}/Source/unit_test_framework.h)

	set_target_properties(${BINARY} PROPERTIES LINKER_LANGUAGE CXX)

	target_compile_options(
		${BINARY} 
		PUBLIC 
		/W3 /nologo /EHsc
		"$<$<CONFIG:Debug>:/MTd;/Od;/Ob0;/Zi;/RTC1;/DDEBUG;/D_DEBUG>"
		"$<$<CONFIG:Release>:/MT;/O2;/Ob2;/DNDEBUG>"
	)

	## Put all Examples into the Examples folder
	set_target_properties (${BINARY} PROPERTIES FOLDER ${EXAMPLES_FOLDER_NAME})

endforeach()