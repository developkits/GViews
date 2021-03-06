
#ifndef __view_mediaplayer_view_h__
#define __view_mediaplayer_view_h__

#include "wmp.tlh" 
#include "activex_host.h"
#include "ui/views/view.h"

namespace views
{

    class VIEWS_EXPORT MediaPlayerView : public View, public AxHostDelegate
    {
    public:
        explicit MediaPlayerView();
        virtual ~MediaPlayerView();

        WMPLib::IWMPPlayer4* wmp() const { return wmp_; }
        bool Play(const std::wstring& url);

        // Overridden from View:
        virtual bool OnSetCursor(const gfx::Point& p);
        virtual bool OnMousePressed(const ui::MouseEvent& event);
        virtual bool OnMouseDragged(const ui::MouseEvent& event);
        virtual void OnMouseReleased(const ui::MouseEvent& event);
        virtual void OnMouseMoved(const ui::MouseEvent& event);
        virtual bool OnKeyPressed(const ui::KeyEvent& event);
        virtual bool OnKeyReleased(const ui::KeyEvent& event);

    protected:
        // Overridden from View:
        virtual void OnPaint(gfx::Canvas* canvas);
        virtual void Layout();
        virtual void ViewHierarchyChanged(bool is_add, View* parent, View* child);

        // Overridden from AxHostDelegate:
        virtual HWND GetAxHostWindow() const;
        virtual void OnAxCreate(AxHost* host);
        virtual void OnAxInvalidate(const gfx::Rect& rect);

    private:
        scoped_ptr<AxHost> ax_host_;
        base::win::ScopedComPtr<WMPLib::IWMPPlayer4> wmp_;

        bool initialized_;
    };

} //namespace view

#endif //__view_mediaplayer_view_h__