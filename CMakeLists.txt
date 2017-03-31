cmake_minimum_required(VERSION 3.5)
project(2_Praktikum_VS)

set(CMAKE_C_STANDARD 99)
set(CMAke_C_COMPILER /usr/bin/gcc)

set(SOURCE_RDICT rdict_clnt.c rdict_cif.c rdict.c rdict_xdr.c)
add_executable(rdict ${SOURCE_RDICT})

set(SOURCE_RDICTD rdict_svc.c rdict_sif.c rdict_srp.c rdict_xdr.c)
add_executable(rdictd ${SOURCE_RDICTD})

add_custom_command(OUTPUT rdict.h
        COMMAND rpcgen ${CMAKE_SOURCE_DIR}/rdict.x
        DEPENDS rdict.x)

add_definitions(-DRPC_SVC_FG)
