#include "myurl.h"

Myurl::Myurl()
{
    base_url="http://localhost:3000";

}

const QString &Myurl::getBase_url() const
{
    return base_url;
}
