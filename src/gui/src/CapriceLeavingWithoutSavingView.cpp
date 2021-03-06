#include "CapriceLeavingWithoutSavingView.h"

CapriceLeavingWithoutSavingView::CapriceLeavingWithoutSavingView(SDL_Surface* surface, SDL_Surface* backSurface, const CRect& WindowRect) : CView(surface, backSurface, WindowRect)
{
  CMessageServer::Instance().RegisterMessageClient(this, CMessage::CTRL_MESSAGEBOXRETURN);
  m_pMessageBox = new wGui::CMessageBox(CRect(CPoint(m_ClientRect.Width() /2 - 125, m_ClientRect.Height() /2 - 40), 250, 80), this, nullptr, "Quit without saving?", "Unsaved changes. Do you really want to quit?", CMessageBox::BUTTON_YES | CMessageBox::BUTTON_NO);
  m_pMessageBox->SetModal(true);
}

bool CapriceLeavingWithoutSavingView::Confirmed()
{
  return confirmed;
}

void CapriceLeavingWithoutSavingView::PaintToSurface(SDL_Surface& ScreenSurface, SDL_Surface& FloatingSurface, const CPoint& Offset) const
{
  if (m_bVisible)
  {
    // Reset backgound
    SDL_BlitSurface(m_pBackSurface, nullptr, &ScreenSurface, nullptr);

    // Draw all child windows recursively
    for (const auto child : m_ChildWindows)
    {
      if (child)
      {
        child->PaintToSurface(ScreenSurface, FloatingSurface, Offset);
      }
    }
  }
}

bool CapriceLeavingWithoutSavingView::HandleMessage(CMessage* pMessage)
{
  bool bHandled = false;

  if (pMessage)
  {
    switch(pMessage->MessageType())
    {
      case CMessage::APP_DESTROY_FRAME:
        {
          // Exit gui
          CMessageServer::Instance().QueueMessage(new CMessage(CMessage::APP_EXIT, nullptr, this));
          break;
        }

      case CMessage::CTRL_MESSAGEBOXRETURN:
        {
          wGui::CValueMessage<CMessageBox::EButton> *pValueMessage = dynamic_cast<CValueMessage<CMessageBox::EButton>*>(pMessage);
          if (pValueMessage && pValueMessage->Value() == CMessageBox::BUTTON_YES)
          {
            confirmed = true;
          }
          // Exit gui
          CMessageServer::Instance().QueueMessage(new CMessage(CMessage::APP_EXIT, nullptr, this));
          break;
        }

      default :
        break;
    }
  }
  if (!bHandled) {
    bHandled = CView::HandleMessage(pMessage);
  }
  return bHandled;
}
