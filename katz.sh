ALGORITHM=Katz
WORKERS=2
GRAPH=input/katz
RESULT=result/katz
NODES=1000000
SNAPSHOT=1
TERMTHRESH=0.0001
BUFMSG=500
PORTION=0.1
SOURCE=0
BETA=0.007
INITC=100000000

./maiter  --runner=$ALGORITHM --workers=$WORKERS --graph_dir=$GRAPH --result_dir=$RESULT --num_nodes=$NODES --katz_source=$SOURCE --katz_beta=$BETA --katz_initc=$INITC --snapshot_interval=$SNAPSHOT --portion=$PORTION --termcheck_threshold=$TERMTHRESH --bufmsg=$BUFMSG --v=0 > log


