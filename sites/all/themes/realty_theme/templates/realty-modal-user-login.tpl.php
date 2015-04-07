<div class="modal fade registration" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-reg zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <?php print $logo;?>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $image_close;?>
      </button>
    </div>
    <div class="col-xs-12 registration-tab-block zero-padding">
      <ul  id="menureg" role="tablist">
        <a href="#reg" role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
          <li  class="reg-item reg-active" role="presentation">Регистрация</li>
        </a>
        <a href="#enter" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
          <li class="reg-item" role="presentation">Вход</li>
        </a>
      </ul>
    </div>

    <div class="tab-content">
      <div role="tabpanel" class="tab-pane fade active in" id="reg" aria-labelledby="home-tab">
        <div class="col-xs-12 reg-line">
          <?php print render($register_form);?>
        </div>
      </div>

      <div role="tabpanel" class="tab-pane fade" id="enter" aria-labelledby="profile-tab">
        <div class="col-xs-12 hint-reg-line">
        </div>
        <?php print render($login_form);?>
      </div>
    </div>
  </div>
</div>