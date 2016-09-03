// COLMAP - Structure-from-Motion.
// Copyright (C) 2016  Johannes L. Schoenberger <jsch at inf.ethz.ch>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "ui/license_widget.h"

namespace colmap {

LicenseWidget::LicenseWidget(QWidget* parent) : QTextEdit(parent) {
  setReadOnly(true);
  setWindowFlags(Qt::Dialog);
  resize(parent->width() - 20, parent->height() - 20);
  setWindowTitle("License");

  QString licenses;
  licenses += "<h2>COLMAP</h2>";
  licenses += GetCOLMAPLicense();
  licenses += "<h2>External</h2>";
  licenses += "<h3>FLANN</h3>";
  licenses += GetFLANNLicense();
  licenses += "<h3>PBA</h3>";
  licenses += GetPBALicense();
  licenses += "<h3>SiftGPU</h3>";
  licenses += GetSiftGPULicense();
  licenses += "<h3>SQLite</h3>";
  licenses += GetSQLiteLicense();
  licenses += "<h3>VLFeat</h3>";
  licenses += GetVLFeatLicense();
  setHtml(licenses);
}

QString LicenseWidget::GetCOLMAPLicense() const {
  const QString license =
      "Copyright (C) 2016  Johannes L. Schoenberger <jsch at inf.ethz.ch><br>"
      "This program is free software: you can redistribute it and/or modify<br>"
      "it under the terms of the GNU General Public License as published by<br>"
      "the Free Software Foundation, either version 3 of the License, or<br>"
      "(at your option) any later version.<br><br>"
      "This program is distributed in the hope that it will be useful,<br>"
      "but WITHOUT ANY WARRANTY; without even the implied warranty of<br>"
      "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the<br>"
      "GNU General Public License for more details.<br><br>"
      "You should have received a copy of the GNU General Public License<br>"
      "along with this program.  If not, see <http://www.gnu.org/licenses/>.";
  return license;
}

QString LicenseWidget::GetFLANNLicense() const {
  const QString license =
      "The BSD License<br>"
      "<br>"
      "Copyright (c) 2008-2011  Marius Muja (mariusm@cs.ubc.ca). "
      "All rights reserved.<br>"
      "Copyright (c) 2008-2011  David G. Lowe (lowe@cs.ubc.ca). "
      "All rights reserved.<br>"
      "<br>"
      "Redistribution and use in source and binary forms, with or without<br>"
      "modification, are permitted provided that the following conditions<br>"
      "are met:<br>"
      "<br>"
      " * Redistributions of source code must retain the above copyright<br>"
      "   notice, this list of conditions and the following disclaimer.<br>"
      " * Redistributions in binary form must reproduce the above copyright<br>"
      "   notice, this list of conditions and the following disclaimer in<br>"
      "   the documentation and/or other materials provided with the<br>"
      "   distribution.<br>"
      " * Neither the name of the \"University of British Columbia\" nor<br>"
      "   the names of its contributors may be used to endorse or promote<br>"
      "   products derived from this software without specific prior<br>"
      "   written permission.<br>"
      "<br>"
      "THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>"
      "\"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>"
      "LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS<br>"
      "FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE<br>"
      "COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,<br>"
      "INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES<br>"
      "(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS<br>"
      "OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS<br>"
      "INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,<br>"
      "WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE<br>"
      "OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,<br>"
      "EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
  return license;
}

QString LicenseWidget::GetPBALicense() const {
  const QString license =
      "Copyright (c) 2011  Changchang Wu (ccwu@cs.washington.edu)<br>"
      "and the University of Washington at Seattle<br>"
      "<br>"
      "This library is free software; you can redistribute it and/or<br>"
      "modify it under the terms of the GNU General Public<br>"
      "License as published by the Free Software Foundation; either<br>"
      "Version 3 of the License, or (at your option) any later version.<br>"
      "<br>"
      "This library is distributed in the hope that it will be useful,<br>"
      "but WITHOUT ANY WARRANTY; without even the implied warranty of<br>"
      "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU<br>"
      "General Public License for more details.";
  return license;
}

QString LicenseWidget::GetSiftGPULicense() const {
  const QString license =
      "Copyright (c) 2007 University of North Carolina at Chapel Hill<br>"
      "All Rights Reserved<br>"
      "<br>"
      "Permission to use, copy, modify and distribute this software and its<br>"
      "documentation for educational, research and non-profit purposes,<br>"
      "without fee, and without a written agreement is hereby granted,<br>"
      "provided that the above copyright notice and the following paragraph<br>"
      "appear in all copies.<br>"
      "<br>"
      "The University of North Carolina at Chapel Hill make no<br>"
      "representations about the suitability of this software for any<br>"
      "purpose. It is provided 'as is' without express or implied warranty.";
  return license;
}

QString LicenseWidget::GetSQLiteLicense() const {
  const QString license =
      "The author disclaims copyright to this source code. In place of<br>"
      "a legal notice, here is a blessing:<br>"
      "May you do good and not evil.<br>"
      "May you find forgiveness for yourself and forgive others.<br>"
      "May you share freely, never taking more than you give.";
  return license;
}

QString LicenseWidget::GetVLFeatLicense() const {
  const QString license =
      "Copyright (C) 2007-11, Andrea Vedaldi and Brian Fulkerson<br>"
      "Copyright (C) 2012-13, The VLFeat Team<br>"
      "All rights reserved.<br>"
      "<br>"
      "Redistribution and use in source and binary forms, with or without<br>"
      "modification, are permitted provided that the following conditions <br>"
      "are met:<br>"
      "1. Redistributions of source code must retain the above copyright<br>"
      "   notice, this list of conditions and the following disclaimer.<br>"
      "2. Redistributions in binary form must reproduce the above copyright<br>"
      "   notice, this list of conditions and the following disclaimer in<br>"
      "   the documentation and/or other materials provided with the<br>"
      "   distribution.<br>"
      "<br>"
      "THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>"
      "AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>"
      "LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS<br>"
      "FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE<br>"
      "COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,<br>"
      "INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,<br>"
      "BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;<br>"
      "LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER<br>"
      "CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT<br>"
      "LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN<br>"
      "ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE<br>"
      "POSSIBILITY OF SUCH DAMAGE.";
  return license;
}

}  // namespace colmap