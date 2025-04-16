# to reset pci device
sudo modprobe -r qdma_pf
echo 1 | sudo tee /sys/bus/pci/devices/0000:01:00.0/remove
echo 1 | sudo tee /sys/bus/pci/rescan
sudo modprobe qdma_pf

# setup qdma queue
echo 512 | sudo tee /sys/bus/pci/devices/0000:01:00.0/qdma/qmax
dma-ctl qdma01000 q add idx 32 mode st dir bi
dma-ctl qdma01000 q start idx 32 dir bi

cp -r ~/Desktop/Dej/MAIN_FPGA/NetFlow_Packet_Analyzer_shell.gen/sources_1/ip/p4_engine .

cp -r ~/netflow-analyzer/p4_engine_for_dev/src/sw/app ./p4_engine/src/sw/

cd p4_engine/src/sw/drivers

make all

cd ../app/p4-ctl

make clean && make all