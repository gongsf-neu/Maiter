#include "client/client.h"
#include <cmath>


using namespace dsm;

//DECLARE_string(graph_dir);
DECLARE_string(result_dir);
DECLARE_int64(num_nodes);
DECLARE_double(portion);

struct con_componentIterateKernel : public IterateKernel<int, int, vector<int> > {
    int zero;


    con_componentIterateKernel() : zero(0){}

    void read_data(string& line, int& k, vector<int>& data){
        string linestr(line);
        int pos = linestr.find("\t");
        if(pos == -1) return;
        
        int source = boost::lexical_cast<int>(linestr.substr(0, pos));

        vector<int> linkvec;
        string links = linestr.substr(pos+1);
        int spacepos = 0;
        while((spacepos = links.find_first_of(" ")) != links.npos){
            int to;
            if(spacepos > 0){
                to = boost::lexical_cast<int>(links.substr(0, spacepos));
            }
            links = links.substr(spacepos+1);
            linkvec.push_back(to);
        }

        k = source;
        data = linkvec;
    }

    //init delta k is the key, delta is delta, data is value
    void init_c(const int& k, int& delta, vector<int>& data){
            int  init_delta = k;
            delta = init_delta;
    }

    void init_v(const int& k,int& v,vector<int>& data){
            v=0;
    }
    void accumulate(int& a, const int& b){
            a=std::max(a,b);
    }
    
    void receive_delta(int& a, const int& b){
        if(a != b){
            a = b;
        }
    }

    void priority(int& pri, const int& value, const int& delta){
            pri = std::abs(value-std::max(value,delta));
//        pri = delta;
    }

    void g_func(const int& k,const int& delta, const int& value, const vector<int>& data, vector<pair<int, int> >* output){
            int outv = value;
            
            //cout << "size " << size << endl;
            for(vector<int>::const_iterator it=data.begin(); it!=data.end(); it++){
                    int target = *it;
                    output->push_back(make_pair(target, outv));
            }
    }

    const int& default_v() const {
        return zero;
    }
    
    const int& min_delta() const {
        return zero;
    }
    
};


static int con_component(ConfigData& conf) {
    MaiterKernel<int, int, vector<int> >* kernel = new MaiterKernel<int, int, vector<int> >(
                                        conf, FLAGS_num_nodes, FLAGS_portion, FLAGS_result_dir,
                                        new Sharding::Mod,
                                        new con_componentIterateKernel,
                                        new TermCheckers<int, int>::Diff);
    
    
    kernel->registerMaiter();

    if (!StartWorker(conf)) {
        Master m(conf);
        m.run_maiter(kernel);
    }
    
    delete kernel;
    return 0;
}

REGISTER_RUNNER(con_component);

