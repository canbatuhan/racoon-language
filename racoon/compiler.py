import os

RUNNER_PATH = "racoon.exe"

def __find_cpp_files(cmd_args, current_directory):
    for file_dir_name in os.listdir(current_directory):
        if ".cpp" in file_dir_name:
            cmd_args.append(os.path.join(
                current_directory, 
                file_dir_name).replace("\\", "/"))

        elif "." not in file_dir_name:
            __find_cpp_files(cmd_args, os.path.join(
                current_directory, 
                file_dir_name).replace("\\", "/"))

def generate_cmd():
    cmd_args = []
    cmd_args.append("g++")
    __find_cpp_files(os.curdir)
    cmd_args.append("-o")
    cmd_args.append(RUNNER_PATH)
    return " ".join(cmd_args)


def compile(cmd):
    os.system(cmd)

def execute():
    os.system(RUNNER_PATH)

if __name__ == "__main__":
    compile(generate_cmd())
