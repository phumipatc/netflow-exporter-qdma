# to reset pci device
sudo modprobe -r qdma_pf
echo 1 | sudo tee /sys/bus/pci/devices/0000:01:00.0/remove
echo 1 | sudo tee /sys/bus/pci/rescan
sudo modprobe qdma_pf

# setup qdma queue
echo 512 | sudo tee /sys/bus/pci/devices/0000:01:00.0/qdma/qmax
dma-ctl qdma01000 q add idx 32 mode st dir bi
dma-ctl qdma01000 q start idx 32 dir bi

cp -r ~/Desktop/Project_V3/Netflow_Packet_Analyzer_v3/Netflow_Packet_Analyzer/Netflow_Packet_Analyzer/Netflow_Packet_Analyzer.gen/sources_1/bd/design_netflow/ip/design_netflow_vitis_net_p4_0_0 .

cp -r ~/netflow-analyzer/p4_engine_for_dev/src/sw/app ./design_netflow_vitis_net_p4_0_0/src/sw/

cd design_netflow_vitis_net_p4_0_0/src/sw/drivers

make all

cd ../app/p4-ctl

make clean && make all