#FLAGS=-g
FLAGS=-Ofast
gcc $FLAGS -c ipaugenblick_main_udp_tx_only.c -o ipaugenblick_main_udp_tx_only.o
gcc ipaugenblick_main_udp_tx_only.o ../ipaugenblick_app_api/build/libipaugenblickservice.a ../../build/libnetinet.a ../../dpdk_libs/libdpdk.a  -lpthread -lrt -ldl -o test_client_udp_tx_only
