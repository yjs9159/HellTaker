#include "yaImage.h"
#include "yaApplication.h"

extern ya::Application application;

namespace ya
{
    ya::Image::Image()
        : mBitmap(NULL)
        , mHdc(NULL)
        , mWidth(0)
        , mHeight(0)
    {
    }

    ya::Image::~Image()
    {
    }

    HRESULT ya::Image::Load(const std::wstring& path)
    {
        mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0
            , LR_LOADFROMFILE | LR_CREATEDIBSECTION);

        if (mBitmap == nullptr)
            return S_FALSE;

        BITMAP info = {};
        GetObject(mBitmap, sizeof(BITMAP), &info);

        mWidth = info.bmWidth;
        mHeight = info.bmHeight;

        HDC mainDC = application.GetHdc();
        mHdc = CreateCompatibleDC(mainDC);

        HBITMAP dafaultBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
        DeleteObject(dafaultBitmap);
        
        
        return S_OK;
    }
}