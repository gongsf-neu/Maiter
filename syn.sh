for ip in `cat ./iplist`
do
#	ssh $ip "tar -zxf myapt/instfile/cmake-3.5.2.tar.gz -C /home/gongsf/myapt/"
	scp -r /home/gongsf/Maiter/conf/mpi-cluster $ip:/home/gongsf/Maiter/conf/
	#ssh $ip "rm -r /home/gongsf/hadoop/conf"
	#scp -r /home/gongsf/hadoop/conf $ip:/home/gongsf/hadoop
	#ssh $ip "rm -r /home/gongsf/.ssh"
done
