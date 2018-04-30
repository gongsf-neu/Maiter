ALGORITHM=Adsorption
WORKERS=2
GRAPH=input/Adsorption
RESULT=result/Adsorption	
NODES=5847570
SNAPSHOT=1
TERMTHRESH=0.0001
BUFMSG=500
PORTION=0.1
DAMPING=0.8




./maiter  --runner=$ALGORITHM --workers=$WORKERS --graph_dir=$GRAPH --result_dir=$RESULT --num_nodes=$NODES --adsorption_damping=$DAMPING --snapshot_interval=$SNAPSHOT --portion=$PORTION --termcheck_threshold=$TERMTHRESH --bufmsg=$BUFMSG --v=0 > static.log


