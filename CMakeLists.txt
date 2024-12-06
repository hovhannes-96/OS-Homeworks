cmake_minimum_required(VERSION 3.30)
project(OS_Homeworks C)

set(CMAKE_C_STANDARD 11)

add_executable(SimpleForkAndExec SimpleForkAndExec.c)
add_executable(MultipleForksAndExecs MultipleForksAndExecs.c)
add_executable(ForkAndExecWithCLA ForkAndExecWithCLA.c)
add_executable(ForkAndExecWithArguments ForkAndExecWithArguments.c)
