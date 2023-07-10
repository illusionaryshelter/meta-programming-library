#pragma once
#define IF(cond,a,b) IF_IMPL(cond,a,b)
#define IF_IMPL(cond,a,b) IF_EVAL(cond,a,b)
#define IF_EVAL(cond,a,b) IF_EVAL_##cond(a,b)
#define IF_EVAL_1(a,b) a
#define IF_EVAL_0(a,b) b
#define PP_CAT_I(a,b) a##b
#define PP_CAT(a,b) PP_CAT_I(a,b)
#define PP_DEFAULT_PARAMS_0(p, v)
#define PP_DEFAULT_PARAMS__0(p) 
#define PP_DEFAULT_PARAMS_1(p, v) p##1 = v
#define PP_DEFAULT_PARAMS__1(p) p##1 
#define PP_DEFAULT_PARAMS_2(p, v) p##1 = v, p##2 = v
#define PP_DEFAULT_PARAMS__2(p) p##1 , p##2
#define PP_DEFAULT_PARAMS_3(p, v) p##1 = v, p##2 = v, p##3 = v
#define PP_DEFAULT_PARAMS__3(p) p##1 , p##2 , p##3 
#define PP_DEFAULT_PARAMS_4(p, v) p##1 = v, p##2 = v, p##3 = v, p##4 = v
#define PP_DEFAULT_PARAMS__4(p) p##1 , p##2 , p##3, p##4 
#define PP_DEFAULT_PARAMS_5(p, v) p##1 = v, p##2 = v, p##3 = v, p##4 = v, p##5 = v
#define PP_DEFAULT_PARAMS__5(p) p##1 , p##2 , p##3 , p##4 , p##5 
#define PP_DEFAULT_PARAMS_6(p, v) p##1 = v, p##2 = v, p##3 = v, p##4 = v, p##5 = v,p##6=v
#define PP_DEFAULT_PARAMS__6(p) p##1 , p##2 , p##3 , p##4 , p##5,p##6 
#define PP_INC_1 2
#define PP_INC_2 3
#define PP_INC_3 4
#define PP_INC_4 5
#define PP_INC_5 6
#define PP_INC_6 0
#define PP_INC(i) PP_CAT(PP_INC_,i)
#define PP_EMPTY()
