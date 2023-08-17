#!/bin/bash

for cpp_file in *.cpp; do
    # 파일 이름에서 확장자를 제거하여 디렉토리 이름으로 사용
	dir_name="${cpp_file%.cpp}"

    if [ -f "$cpp_file" ]; then
        # 디렉토리 생성
        mkdir -p "$dir_name"
        # 파일을 디렉토리로 이동
        mv "$cpp_file" "$dir_name/"
		cp tmpMakefile $dir_name/Makefile
		echo "Moved $cpp_file to $dir_name/"	
	fi
done

