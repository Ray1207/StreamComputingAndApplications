// eJx9UF1PwjAUzf0nhvgAiVm3YXjoG_1JhIkwxDVGfSDPKKFt3m_04ShF9vtykxiqbpwzk9PffcU9kicKqQpLGUBefTfZkSOgib04dOELBNzfl3Jq0tdNpo2QiN3ZMS2uhCOk1HkaJTwbbTfKGjVexOPRxcIjCeLw3NxveT5eRtmGT5dJxf0L0_0nx5Hu6dT0k_0EOM3ms3wyHOnB8GVZi_0s0wLZoFKvIKWkquTa6ZKIFgvZrjeyALq_0sTBVbONyplKLVQjqK2VqShBJL5W0if7VFR9chiMWc839ygoa2C4AYSL1TBM7P12XWoPiMalP8bfr3UmC8cwTVuT_1YFChpcOvJqLX4IkLg_1Fv1nF_1uvvu5VJApWjVZu72bq59k3O31fNgPuxShB7


#include "./ComputeSimilarity.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR ComputeSimilarity_Base
#define MY_OPERATOR ComputeSimilarity$OP




void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{
   IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);
   if (! (1) ) 
       return;
   { OPort0Type otuple(::application::ComputeSimilarityScore(iport$0.get_text1(), iport$0.get_text2())); submit (otuple, 0);
 }
   
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port) 
{
   forwardWindowPunctuation(punct);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("ComputeSimilarity",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator() {
    PE & pe = PE::instance();
    uint32_t index = getIndex();
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("01"));
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    punctLogic (punct, port);
    
    if (punct == Punctuation::FinalMarker) {
        process(punct, port);
        bool forward = false;
        {
            AutoPortMutex $apm($fpMutex, *this);
            $oportBitset.reset(port);
            if ($oportBitset.none()) {
                $oportBitset.set(1);
                forward=true;
            }
        }
        if(forward)
            submit(punct, 0);
        return;
    }
    
    process(punct, port);
}





