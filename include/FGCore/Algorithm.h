#ifndef FGCORE_ALGORITHM_H
#define FGCORE_ALGORITHM_H 1

FG_NS_BEGIN
	// //--------------------------------------------------------------------------
	// //MapFinder:
	// //
	// //--------------------------------------------------------------------------
	// template<typename TK,typename TV>
	// class MapFinder
	// {

 // 	public:

 // 	       inline 
 // 	       bool operator ()(const std::map<TK, TV>::value_type &pair) const
 // 	       {
 // 	            return pair.second == fValue;
 // 	       };

 // 	private:
 // 	        TV &fValue;                    
 // 	};

 // 	template<typename TK,typename TV>
 // 	MapFinder<TK,TV>::MapFinder(const TV &val):fValue(val){ };

	// //--------------------------------------------------------------------------
	// //VectorFinder:
	// //
	// //--------------------------------------------------------------------------
 // 	template<typename TV>
	// class VectorFinder
	// {

 // 	public:
 // 	       VectorFinder(const TV&val):fValue(val){ };

 // 	       inline bool operator ()(const TV &valItr)
 // 	       {
 // 	            return valItr.first == fValue;
 // 	       };

 // 	private:
 // 	        T &fValue;                    
 // 	};
 // 	template<typename TV>
 // 	VectorFinder<TV>::VectorFinder(const TV&val):fValue(val){

 // 	};

	// //--------------------------------------------------------------------------
	// //......:
	// //
	// //--------------------------------------------------------------------------

 FG_NS_END

#endif