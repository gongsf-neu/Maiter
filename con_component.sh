ALGORITHM=con_component
WORKERS=2
GRAPH=input/CC
RESULT=result/CC
NODES=10000000
SNAPSHOT=1
TERMTHRESH=0.1
BUFMSG=500
PORTION=0.2


./maiter  --runner=$ALGORITHM --workers=$WORKERS --graph_dir=$GRAPH --result_dir=$RESULT --num_nodes=$NODES --snapshot_interval=$SNAPSHOT --portion=$PORTION --termcheck_threshold=$TERMTHRESH --bufmsg=$BUFMSG --v=0 > static.log


