<div class="container fin profile-info">
  <div class="col-xs-12 margin-top">
    <div class="col-xs-2 profile-photo">
      <?php print $image; ?>
    </div>
    <div class="col-xs-5 profile-text">

      <p>
        <?php print t('Profile'); ?>
      </p>
      <a href="#" data-toggle="modal" data-target=".fio_change">
        <h2 id="h-name">
          <?php print $name; ?>
        </h2>
      </a>
      <p>
        <?php print t('E-mail'); ?>
      </p>
      <a href="#" data-toggle="modal" data-target=".mail_change">
        <h2 id="h-mail">
          <?php print $mail; ?>
        </h2>
      </a>
      <p>
        <?php print t('Phone'); ?>
      </p>
      <a href="#" data-toggle="modal" data-target=".phone_change">
        <h2 id="h-number">
          <?php print $number; ?>
        </h2>
      </a>

    </div>
  </div>
</div>


<div class="modal fade fio_change" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-profile zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>
          <?php print t('change the Ф.И.О');?>
        </p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $image_close; ?>
      </button>
    </div>
    <div class="col-xs-12 profile-change-item">
      <div class="col-xs-2 text-right zero-padding margin-top-10">
        <?php print $image_man;?>
      </div>
      <div class="col-xs-10 comment-input-item margin-top-10">
        <input id="profile-name" class="form-control comment-input" value="<?php print $name; ?>">
      </div>
    </div>
    <button type="button" class="col-xs-4 col-xs-offset-4 profile-edit comment-button margin-top-35" aria-hidden="true">Изменить
    </button >

  </div>
</div>
<!--    End fio_change -->

<!--  mail_change   -->
<div class="modal fade mail_change" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-profile zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>
          <?php print t('change the E-mail');?>
        </p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $image_close; ?>
      </button>
    </div>
    <div class="col-xs-12 profile-change-item">
      <div class="col-xs-2 text-right zero-padding margin-top-10">
        <?php print $image_mail; ?>
      </div>
      <div class="col-xs-10 comment-input-item margin-top-10">
        <input id="profile-mail" class="form-control comment-input" value="<?php print $mail; ?>">
      </div>
    </div>
    <button type="button" class="col-xs-4 col-xs-offset-4 profile-edit comment-button margin-top-35" aria-hidden="true">Изменить
    </button >

  </div>
</div>
<!--    End mail_change -->

<!--  phone_change   -->
<div class="modal fade phone_change" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-profile zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>
          <?php print t('change the phone number');?>
        </p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $image_close; ?>
      </button>
    </div>
    <div class="col-xs-12 profile-change-item">
      <div class="col-xs-2 text-right zero-padding margin-top-10">
        <?php print $image_phone; ?>
      </div>
      <div class="col-xs-10 comment-input-item margin-top-10">
        <input id="profile-phone" class="form-control comment-input" value="<?php print $number; ?>">
      </div>
    </div>
    <button type="button" class="col-xs-4 col-xs-offset-4 profile-edit comment-button margin-top-35" aria-hidden="true">Изменить
    </button >
  </div>
</div>