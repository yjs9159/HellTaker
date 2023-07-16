#include "yaTexture.h"
#include "yaApplication.h"

extern ya::Application application;

namespace ya
{
    ya::Texture::Texture()
        : mImage(nullptr)
        , mBitmap(NULL)
        , mHdc(NULL)
        , mWidth(0)
        , mHeight(0)
        , mType(eTextureType::None)
    {
    }

    ya::Texture::~Texture()
    {
        delete mImage;
        mImage = nullptr;

        DeleteObject(mBitmap);
        mBitmap = NULL;
    }

    HRESULT ya::Texture::Load(const std::wstring& path)
    {
        // bmp 일때
        // png 일때

        std::wstring ext = path.substr(path.find_last_of(L".") + 1);

        if (ext == L"bmp")
        {
            mType = eTextureType::Bmp;
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
        }
        else if (ext == L"png")
        {
            mType = eTextureType::Png;
            // image.png 파일을 이용하여 Image 객체를 생성합니다
            mImage = Gdiplus::Image::FromFile(path.c_str());

            mWidth = mImage->GetWidth();
            mHeight = mImage->GetHeight();
        }

        return S_OK;
    }
}