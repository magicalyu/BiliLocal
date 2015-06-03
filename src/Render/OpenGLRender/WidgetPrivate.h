#pragma once

#include "OpaquePrivate.h"
#include "../../Local.h"
#include <QOpenGLWidget>

class OpenGLWidgetRenderPrivate :public OpenGLOpaqueRenderPrivate
{
public:
	OpenGLWidgetRenderPrivate();

	virtual bool isVisible() override
	{
		return widget->isVisible();
	}

	virtual quintptr getHandle() override
	{
		return (quintptr)widget;
	}

	virtual void resize(QSize size) override
	{
		widget->resize(size);
	}

	virtual QSize getActualSize() override
	{
		return widget->size();
	}

	virtual void draw(QRect rect) override
	{
		widget->update(rect);
	}

private:
	QOpenGLWidget *widget;
};
