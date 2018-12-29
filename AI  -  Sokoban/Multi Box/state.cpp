#include "state.h"


state::state()
{
	

}


state::~state(void)
{
}

//state state::operator = (state &s)
//{
//	state st;
//
//	st.xs = s.xs;
//	st.ys = s.ys;
//	st.xb = s.xb;
//	st.yb = s.yb;
//
//	return st;
//
//}

void state::setState(int x1,int y1,int x2,int y2)
{
	xs = x1;
	ys = y1;
	xb = x2;
	yb = y2;
}