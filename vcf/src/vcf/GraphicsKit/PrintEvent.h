#ifndef _PRINTEVENT_H__
#define _PRINTEVENT_H__



namespace VCF {
	class PrintContext;
	/**
	class PrintEvent documentation
	*/
	class GRAPHICSKIT_API PrintEvent : public Event{
	public: 		
		PrintEvent( Object* source, PrintContext* ctx, ulong32 type ): Event(source,type),context_(ctx){
			pageBounds_ = ctx->getViewableBounds();
		}
		
		PrintEvent( const PrintEvent& rhs ): Event(rhs),context_(rhs.context_), pageBounds_(rhs.pageBounds_) {
			
		}

		PrintContext* getPrintContext() {
			return context_;
		}
		
		
		virtual Object* clone( bool deep=false ) {
			return new PrintEvent(*this);
		}
		
		Rect getPageBounds() {
			return pageBounds_;
		}
	protected:
		PrintContext* context_;
		Rect pageBounds_;
		
	};
	
	
	
};




#endif //_PRINTEVENT_H__



