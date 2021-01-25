using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Client_Server_Proj.Models;

namespace Client_Server_Proj.Controllers
{
    public class FeedbackController : Controller
    {
        private CommentData database = new CommentData();
        // GET: Feedback
        public ActionResult Comments()
        {
            var entriesDescending = (from entry in database.Entries orderby entry.CurrDate descending select entry).Take(20);
            ViewBag.Entries = entriesDescending.ToList();
            return View();
        }

        public ActionResult Submit()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Submit(CommentEntry entry)
        {
            entry.CurrDate = DateTime.Now;
            database.Entries.Add(entry);
            database.SaveChanges();
            return RedirectToAction("Comments");
        }
    }
}