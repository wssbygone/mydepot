#include <cstdint>
#include <set>

class CWrapperDiag {
public:
    static CWrapperDiag* instance();
    ~CWrapperDiag();
	static std::set<CWrapperDiag*> sCwpd_;	
	
private:
    CWrapperDiag();
    CWrapperDiag(const CWrapperDiag&) = delete;
    const CWrapperDiag& operator=(const CWrapperDiag&) = delete;
	

};

