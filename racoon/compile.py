import os

COMPILE_CMD = []

def generate_cmd():
    global COMPILE_CMD
    COMPILE_CMD.append("gcc")
    __find_c_files(os.curdir)
    COMPILE_CMD.append("-o")
    COMPILE_CMD.append("racoon.exe")
    return " ".join(COMPILE_CMD)

def __find_c_files(current_directory):
    global COMPILE_CMD

    for file_dir_name in os.listdir(current_directory):
        if ".c" in file_dir_name:
            COMPILE_CMD.append(os.path.join(
                current_directory, 
                file_dir_name).replace("\\", "/"))

        elif "." not in file_dir_name:
            __find_c_files(os.path.join(
                current_directory, 
                file_dir_name).replace("\\", "/"))


if __name__ == "__main__":
    COMPILE_CMD = generate_cmd()
    os.system(COMPILE_CMD)
