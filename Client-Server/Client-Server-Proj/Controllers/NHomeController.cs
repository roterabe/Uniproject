using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Client_Server_Proj.Controllers
{
    public class NHomeController : Controller
    {
        // GET: NHome
        public ActionResult Main()
        {
            return View();
        }
        public ActionResult Gallery()
        {
            return View();
        }

        public ActionResult Downloads()
        {
            return View();
        }
    }
}